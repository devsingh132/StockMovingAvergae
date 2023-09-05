Assumptions:
    • Initially For each algo, the instruments is initialized with the same stocks as in the input file.
    • The start and end time in the config file are in the format yyyy-mm-dd HH:MM:SS format.
    • In the 1st entry of each row of the input file is the time which follows the format yyyy-mm-dd HH:MM:SS.
    • In case the simulation start and end time does not match the starttime is assumed to be the next biggest time for which data is present. And end time is assumed to be the greatest element less than the endtime.
    • The precision of the data can differ.

Build:
	./release.sh
Run:
    • ./start.sh <InputFile> <configFile>
    • The process runs in background and the logs generated are redirected to logs/<data.log>