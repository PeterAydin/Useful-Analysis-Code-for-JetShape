#!/opt/star/sl73_gcc485/bin/perl

# input parameters for type of files to merge and for specific pt bin of event plane corrections/calculations
($RunType, $MYPWD, $BNLuserName) = @ARGV;
system("echo", "RunType: $RunType \n");

#need to update the runlist
# check type for name formatting
if($RunType eq "Run14") {
	$runList="runlistP17id"; #runlist Run14 AuAu
} elsif($RunType eq "Run16") {
	$runList="runlistP16ij"; #runlist - all RUNS listed non-repeating
} 
$NFiles="\"all\"";

# set directories
$workingDir="$MYPWD";
# these should hopefully be able to be redirected elsewhere
$schedDir="$workingDir/sched";   # scheduling files
$outDir="/gpfs01/star/pwg/$BNLuserName/output/temp";        # output file: for more space
$logDir="$workingDir/subErr";    # error files

# open runlist and count up # of runs - May15, added '<'
open(FILE, '<', $runList); 
@runs=<FILE>;
$nRuns=$#runs; # get number runs in file

# set number of runs for each dataset
if($RunType eq "Run14") {
        $nRuns=$#runs; #runlist Run14 AuAu
} elsif($RunType eq "Run16") {
        $nRuns=1308;   #runlist - all RUNS listed non-repeating
} 

# close file
close $FILE;

# print current run, loop over runs and chomp off new line from name
print "$nRuns in $runList \n";
for($i=0;$i<=$nRuns;$i++){ # loop over nRuns
#for($i=0;$i<1;$i++){ # loop to 0 - for testing 1 RUN
#for($i=0;$i<5;$i++){ # test with 50 Runs
    chomp($runs[$i]);
 print "$i: run = $runs[$i]\n";

 print "Writing xml file for Run $runs[$i]:\n";
 open (OUTFILE, "> $schedDir/mysched_$runs[$i]_$i.xml");
 print(OUTFILE "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \n");
# set simulateSubmission="true" in order to test and not submit
 # June14, change minFilesPerProcess: 20-30
if($RunType eq "Run14") { 
  print(OUTFILE "<job name=\"AuAu200GeVRun14\" maxFilesPerProcess=\"30\" fileListSyntax = \"paths\" simulateSubmission=\"false\" > \n");
} elsif($RunType eq "Run16") {
  print(OUTFILE "<job name=\"AuAu200GeVRun16\" maxFilesPerProcess=\"20\" fileListSyntax = \"paths\" simulateSubmission=\"false\" > \n");
}
 # TEST
# print(OUTFILE "<job name=\"AuAu200GeVRun16\" filesPerHour=\"2\" minFilesPerProcess=\"18\" maxFilesPerProcess=\"20\" fileListSyntax = \"paths\" simulateSubmission=\"true\" > \n");

 # commands to runs for each job - set environment
 print(OUTFILE "<command>  \n");
 print(OUTFILE "    starver SL17f \n");
# print(OUTFILE "    starver pro \n");
 print(OUTFILE "    setenv FASTJET /star/u/pna16/research/fastjet-install \n");   # FIXME 1 (good)
# print(OUTFILE "    root -q -b readPicoDst.C\\\(\\\"\$FILELIST\\\"\\\,\\\"testOUT_$runs[$i]_\$JOBID.root\\\"\\\,1000000000\\\,\\\"_$runs[$i]_\$JOBID\\\"\\\) \n");
 print(OUTFILE "    root -q -b readPicoDstTest.C\\\(\\\"\$FILELIST\\\"\\\,\\\"testOUT_$runs[$i]_\$JOBID.root\\\"\\\,1000000000\\\,\\\"_$runs[$i]_\$JOBID\\\"\\\) \n");  # FIXME 2 (good)
 print(OUTFILE "</command> \n");

 # this generator currenly works Aug13: sorts generated files to specific folders
 print(OUTFILE "<Generator> \n");
 print(OUTFILE "    <Location> ./myJobFiles </Location> \n"); # sorting files by folder
 print(OUTFILE "    <ScriptLocation> ./myJobScripts </ScriptLocation> \n");
 print(OUTFILE "    <ListLocation> ./myJobLists </ListLocation> \n");
 print(OUTFILE "</Generator> \n");

 # sandbox to copy files to scratch to run from there before copying back
 #print(OUTFILE "<Sandbox> \n");
 #print(OUTFILE "<Package> \n");
 print(OUTFILE "<SandBox installer=\"ZIP\"> \n"); # ZIPs sandbox
 print(OUTFILE "    <Package name=\"myExec\"> \n"); # names the package
 print(OUTFILE "        <File>file:./StRoot/</File> \n");
 print(OUTFILE "        <File>file:./fastjet-install/ </File> \n");  # FIXME 3 (good)
 print(OUTFILE "        <File>file:./fastjet-install/include/fastjet/ </File> \n"); # FIXME 4 (good)
 print(OUTFILE "        <File>file:./fastjet-install/include/siscone/ </File> \n"); # FIXME 5 (good)
 print(OUTFILE "        <File>file:./.sl73_gcc485/ </File> \n"); # FIXME 6 (good)
 print(OUTFILE "        <File>file:./readPicoDstTest.C </File> \n"); # FIXME 7 (good)
 print(OUTFILE "    </Package> \n");
 print(OUTFILE "</SandBox> \n");

 # set output streams
 print(OUTFILE "<stdout URL=\"file:$logDir/output_$runs[$i]_\$JOBID.log\"/>  \n");
 print(OUTFILE "<stderr URL=\"file:$logDir/output_$runs[$i]_\$JOBID.err\"/>  \n");
# print(OUTFILE "<input URL=\"catalog:star.bnl.gov?production=P16ij,sanity=1,filename~st_physics,runnumber=$runs[$i]\" nFiles=$NFiles />  \n");
# use this for run by run output 10->all Nov3, 2017
if($RunType eq "Run14") {
  print(OUTFILE "<input URL=\"filelist:$MYPWD/filelists/Run14AuAu/Run_$runs[$i]_files.list\"  nFiles=\"all\" /> \n");
} elsif($RunType eq "Run16") {
  print(OUTFILE "<input URL=\"filelist:$MYPWD/filelists/Run16AuAu/Run_$runs[$i]_files.list\"  nFiles=\"all\" /> \n");
}

 # copy output .root files from Scratch to output directory
 print(OUTFILE "<output fromScratch=\"*.root\" toURL=\"file:$outDir/\" /> \n");
 print(OUTFILE "</job> \n");
 close(OUTFILE);

 # submit jobs
 print system "cd $schedDir";
 print "Submitting jobs to Condor for job # $i: \n";
 # the "-u ie" forces submission when # files in a run is less than # filesPerProcess (prevents user intervention)
# print system "star-submit -u ie $schedDir/mysched_$runs[$i]_$i.xml";
 print system "star-submit $schedDir/mysched_$runs[$i]_$i.xml";
}
