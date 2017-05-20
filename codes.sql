use mpicl;
TRUNCATE TABLE Codes;

INSERT INTO Codes(code, name, description, category) VALUES(-2,"EVENTMARK","key for event mark","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-3,"EVENTENTRY","key for event entry","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-4,"EVENTEXIT","key for event exit","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-5,"EVENTLABEL","key for event label","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-6,"EVENTDD","key for event data descriptor","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-7,"EVENTMESSAGE","key for event message","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-101,"TIMESTAT","key for time statistics","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-102,"COUNTSTAT","key for count statistics","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-103,"SENDVOLSTAT","key for send volume statistics","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-104,"RECVVOLSTAT ","key for receive volume statistics","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-105,"SIZEVOLSTAT","key for processor subset definition ","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-201,"MACHINESUBSET","key for processor subset definition ","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-202,"PROCESSSUBSET ","key for process subset definition","record type definitions");

INSERT INTO Codes(code, name, description, category) VALUES(-203,"EVENTSUBSET","key for event type subset definition","record type definitions");


INSERT INTO Codes(code, name, description, category) VALUES(-1,"WILDCARD","wildcard for all or any processes","event type definitions");


INSERT INTO Codes(code, name, description, category) VALUES(-11,"OPENKEY","key of an open event"," enabling, disabling, and querying ");

INSERT INTO Codes(code, name, description, category) VALUES(-12,"CLOSEKEY ","key of a close event"," enabling, disabling, and querying ");

INSERT INTO Codes(code, name, description, category) VALUES(-13,"WHOKEY","key of a who event"," enabling, disabling, and querying ");

INSERT INTO Codes(code, name, description, category) VALUES(-14,"RECVINFOKEY","key of a set message buffering event"," enabling, disabling, and querying ");

INSERT INTO Codes(code, name, description, category) VALUES(-15,"BUFFERKEY","key of a set message buffering event"," enabling, disabling, and querying ");

INSERT INTO Codes(code, name, description, category) VALUES(-16,"COMMCHECKKEY","key of a generic communications status request event"," enabling, disabling, and querying ");



INSERT INTO Codes(code, name, description, category) VALUES(-21,"SENDKEY ","key of a generic send event ","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-22,"BSENDKEY ","key of a buffered send event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-23,"SSENDKEY ","key of a synchronous send event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-24,"RSENDKEY ","key of a ready send event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-27,"SENDBEGKEY ","key of a generic send begin event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-28,"SENDDONEKEY  ","key of a \"done\" generic send status request events","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-29,"SENDNOTDONEKEY ","key of a \"not done\" generic send status request event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-30,"SENDENDKEY ","key of a \"not blocked\" generic send end event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-31,"SENDENDBLOCKKEY ","key of a \"blocked\" generic send end event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-32,"SENDCANCELKEY ","key of a \"canceled\" generic send begin event ","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-33,"BSENDBEGKEY  ","key of a buffered send begin event ","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-34,"BSENDDONEKEY ","key of a \"done\" buffered send status request event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-35,"BSENDNOTDONEKEY","key of a \"not done\" buffered send status request  event ","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-36,"BSENDENDKEY  ","key of a \"blocked\" buffered send end even","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-37,"BSENDENDBLOCKKEY ","key of a \"canceled\" buffered send begin event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-38,"BSENDCANCELKEY  ","key of a \"canceled\" buffered send begin event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-39,"SSENDBEGKEY ","key of a synchronous send begin event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-40,"SSENDDONEKEY  ","key of a \"done\" synchronous send status request  event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-41,"SSENDNOTDONEKEY  ","key of a \"not done\" synchronous send status  request event ","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-42,"SSENDENDKEY ","key of a \"not blocked\" synchronous send end event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-43,"SSENDENDBLOCKKEY ","key of a \"blocked\" synchronous send end even","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-44,"SSENDCANCELKEY","key of a \"canceled\" synchronous send begin event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-45," RSENDBEGKEY  ","key of a ready send begin event ","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-46,"RSENDDONEKEY ","key of a \"done\" ready send status request event *","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-47,"RSENDNOTDONEKEY "," key of a \"not done\" ready send status request  event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-48,"RSENDENDKEY ","key of a \"not blocked\" ready send end event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-49,"RSENDENDBLOCKKEY","key of a \"blocked\" ready send end event","send events");

INSERT INTO Codes(code, name, description, category) VALUES(-50,"RSENDCANCELKEY","key of a \"canceled\" ready send begin event","send events");



INSERT INTO Codes(code, name, description, category) VALUES(-51,"RECVKEY ","key of a \"not blocked\" receive event","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-52,"RECVBLOCKKEY ","key of a \"blocked\" receive event","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-53,"FOUNDKEY ","key of a \"found\" nonblocking probe event","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-54,"NOTFOUNDKEY ","key of a \"not found\" nonblocking probe event ","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-55,"WAITKEY ","key of a \"not blocked\" blocking probe event","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-56,"WAITBLOCKKEY  ","key of a \"blocked\" blocking probe event ","receive events");


INSERT INTO Codes(code, name, description, category) VALUES(-57,"RECVBEGKEY ","key of a receive begin event ","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-58,"RECVDONEKEY  ","key of a \"done\" receive status request event ","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-59,"RECVNOTDONEKEY  ","key of a \"not done\" receive status request event","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-60,"RECVENDKEY ","key of a \"not blocked\" receive end event","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-61,"RECVENDBLOCKKEY ","key of a \"blocked\" receive end event ","receive events");

INSERT INTO Codes(code, name, description, category) VALUES(-62,"RECVCANCELKEY ","key of a \"canceled\" receive begin event","receive events");



INSERT INTO Codes(code, name, description, category) VALUES(-201,"FILEOPENKEY","key of a \"channel or file open\" event ","disk i//o events");

INSERT INTO Codes(code, name, description, category) VALUES(-202,"FILECLOSEKEY  ","key of a \"channel or file close\" event ","disk i//o events");

INSERT INTO Codes(code, name, description, category) VALUES(-221,"WRITEKEY","key of a \"channel or file write\" event","disk i//o events");

INSERT INTO Codes(code, name, description, category) VALUES(-251,"READKEY","key of a \"canceled\" receive begin event","disk i//o events");


INSERT INTO Codes(code, name, description, category) VALUES(-401,"CLOCKSYNCKEY","key of a \"clock sync\" event","synchronization events");

INSERT INTO Codes(code, name, description, category) VALUES(-402,"BARRIERKEY","key of a \"barrier\" event ","synchronization events");


INSERT INTO Codes(code, name, description, category) VALUES(-501,"GETPROCSKEY ","key of an \"allocate processors\" event ","resource allocation events");

INSERT INTO Codes(code, name, description, category) VALUES(-502,"RELPROCSKEY ","key of a \"release processors\" event","resource allocation events");

INSERT INTO Codes(code, name, description, category) VALUES(-503,"LOADKEY","key of a \"spawn process\" event","resource allocation events");


INSERT INTO Codes(code, name, description, category) VALUES(-601,"RIDLEKEY","key of a \"generic idle block\" event ","generic labelling events");

INSERT INTO Codes(code, name, description, category) VALUES(-602,"SYSTEMOHKEY","kkey of a \"generic user overhead\" event ","generic labelling events");

INSERT INTO Codes(code, name, description, category) VALUES(-603,"USEROHKEY ","key of a \"generic user overhead\" event","generic labelling events");


INSERT INTO Codes(code, name, description, category) VALUES(-756,"PACKKEY ","key of a MPI_Pack event","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-773,"UNPACKKEY ","key of a MPI_Unpack event","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-780,"ALLGATHERKEY","key of a MPI_Allgather event","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-782,"ALLREDUCEKEY ","key of a MPI_Allreduce event","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-783,"ALLTOALLKEY","key of a MPI_Alltoall event ","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-785,"BCASTKEY","key of a MPI_Bcast event","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-786,"GATHERKEY"," key of a MPI_Gather event ","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-790,"REDUCEKEY","key of a MPI_Reduce event","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-791,"REDUCESCATTERKEY","key of a MPI_Reduce_scatter event","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-792,"SCANKEY","key of a MPI_Scan event","MPI-specific point-to-point  and collective communication events");

INSERT INTO Codes(code, name, description, category) VALUES(-793,"SCATTERKEY "," key of a MPI_Scatter event ","MPI-specific point-to-point  and collective communication events");



INSERT INTO Codes(code, name, description, category) VALUES(-804,"COMMCREATEKEY","key for MPI_Comm_create event","MPI-specific context events");

INSERT INTO Codes(code, name, description, category) VALUES(-805,"COMMDUPKEY","key for MPI_Comm_dup event ","MPI-specific context events");

INSERT INTO Codes(code, name, description, category) VALUES(-806,"COMMFREEKEY","key for MPI_Comm_free event","MPI-specific context events");

INSERT INTO Codes(code, name, description, category) VALUES(-812,"COMMSPLITKEY ","key for MPI_Comm_split event","MPI-specific context events");

INSERT INTO Codes(code, name, description, category) VALUES(-826,"INTERCOMMCREATEKEY","key for MPI_Intercomm_create event","MPI-specific context events");

INSERT INTO Codes(code, name, description, category) VALUES(-827,"INTERCOMMMERGEKEY","key for MPI_Intercomm_merge event","MPI-specific context events");

INSERT INTO Codes(code, name, description, category) VALUES(-841,"CARTCREATEKEY","key for MPI_Cart_create event","MPI-specific context events");

INSERT INTO Codes(code, name, description, category) VALUES(-846,"CARTSUBKEY","key for MPI_Cart_sub event","MPI-specific context events");

INSERT INTO Codes(code, name, description, category) VALUES(-849,"GRAPHCREATEKEY","key for MPI_Graph_create event","MPI-specific context events");



INSERT INTO Codes(code, name, description, category) VALUES(-901,"TRACEKEY","key of \"tracenode or host or exit\" events","tracing set-up and clean-up routines");

INSERT INTO Codes(code, name, description, category) VALUES(-902,"TSTATSKEY","key of a \"trace events\" event","tracing set-up and clean-up routines");

INSERT INTO Codes(code, name, description, category) VALUES(-903,"TFILESKEY","key of a \"trace files\" event","tracing set-up and clean-up routines");

INSERT INTO Codes(code, name, description, category) VALUES(-904,"TLEVELKEY","key of a \"trace level\" event","tracing set-up and clean-up routines");

INSERT INTO Codes(code, name, description, category) VALUES(-905,"TINFOKEY","key of a \"trace info\" event","tracing set-up and clean-up routines");



INSERT INTO Codes(code, name, description, category) VALUES(-911,"TMSGKEY","key of a \"trace message\" event","trace save or flushing events");

INSERT INTO Codes(code, name, description, category) VALUES(-912,"TFLUSHKEY","key of a \"trace flush\" event ","trace save or flushing events");

INSERT INTO Codes(code, name, description, category) VALUES(-913,"TFULLKEY","key of a \"trace \" event","trace save or flushing events");

INSERT INTO Codes(code, name, description, category) VALUES(-914,"TWRAPKEY","key of a \"trace overwrite\" event","trace save or flushing events");



INSERT INTO Codes(code, name, description, category) VALUES(-1001,"USERSUBSETKEY","key for user event subset","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1002,"PICLSUBSETKEY","key for communication event subset","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1011,"COMMSUBSETKEY","key for communication event subset ","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1012,"SENDSUBSETKEY","key for send event subset ","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1013,"RECVSUBSETKEY","key for receive event subset","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1014,"BLOCKSUBSETKEY","key for blocked communication event subset ","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1201,"IOSUBSETKEY ","key for i//o event subset","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1401,"SYNCSUBSETKEY","key for synchronization event subset","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1501,"ALLOCSUBSETKEY","key for resource allocation event subset","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1601,"GENSUBSETKEY","key for generic event subset","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1901,"TRACESUBSETKEY","key for tracing event subset ","predefined subset aliases");

INSERT INTO Codes(code, name, description, category) VALUES(-1902,"FLUSHSUBSETKEY","key for trace flushing event subset","predefined subset aliases");





