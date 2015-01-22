CC = gcc
CD = cd
STATSAMEDIRPATH = Library/Static/SameDir
STATDIFFDIRPATH = Library/Static/DiffDir
DYNSAMEDIRPATH = Library/Shared/SameDir
DYNDIFFDIRPATH = Library/Shared/DiffDir
FORKPATH = Fork
THREADPATH = threads
SYNMUTPATH = synchronization/UsingMutex
SYNSEMAPATH = synchronization/UsingSemaphore
SIGNALPATH = Signal
IPCPIPEPATH = InterProcessCommunication/pipe
IPCMSGQUEPATH = InterProcessCommunication/MessageQueue
IPCSHMPATH = InterProcessCommunication/SharedMemory
TARGET = statsamedir statdiffdir dynsamedir dyndiffdir fork thread synmutex synsema signal ipcpipe ipcmsgque ipcshm

all: $(TARGET)

statsamedir:
	$(CD) $(STATSAMEDIRPATH); make

statdiffdir:
	$(CD) $(STATDIFFDIRPATH); make

dynsamedir:
	$(CD) $(DYNSAMEDIRPATH); make

dyndiffdir:
	$(CD) $(DYNDIFFDIRPATH); make

fork:
	$(CD) $(FORKPATH); make

thread:
	$(CD) $(THREADPATH); make

synmutex:
	$(CD) $(SYNMUTPATH); make

synsema:
	$(CD) $(SYNSEMAPATH); make

signal:
	$(CD) $(SIGNALPATH); make

ipcpipe:
	$(CD) $(IPCPIPEPATH); make

ipcmsgque:
	$(CD) $(IPCMSGQUEPATH); make

ipcshm:
	$(CD) $(IPCSHMPATH); make

clean:
	$(CD) $(STATSAMEDIRPATH); make clean
	$(CD) $(STATDIFFDIRPATH); make clean
	$(CD) $(DYNSAMEDIRPATH); make clean
	$(CD) $(DYNDIFFDIRPATH); make clean
	$(CD) $(FORKPATH); make clean
	$(CD) $(THREADPATH); make clean
	$(CD) $(SYNMUTPATH); make clean
	$(CD) $(SYNSEMAPATH); make clean
	$(CD) $(SIGNALPATH); make clean
	$(CD) $(IPCPIPEPATH); make clean
	$(CD) $(IPCMSGQUEPATH); make clean
	$(CD) $(IPCSHMPATH); make clean

