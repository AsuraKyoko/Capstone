all: sample
	
sample: ../grom/GromOSAPI/GromOSAPI/GromApp.o ../grom/GromOSAPI/GromOSAPI/GList.o ../grom/GromOSAPI/GromOSAPI/GListEntry.o ../grom/GromOSAPI/GromOSAPI/GMessage.o ../grom/GromOSAPI/GromOSAPI/GMessageInput.o ../grom/GromOSAPI/GromOSAPI/GMessageStart.o ../grom/GromOSAPI/GromOSAPI/GMessageShowList.o ../grom/GromOSAPI/GromOSAPI/GMessagePickList.o sample.o
	g++ -o main -Wall ../grom/GromOSAPI/GromOSAPI/GromApp.o ../grom/GromOSAPI/GromOSAPI/GList.o ../grom/GromOSAPI/GromOSAPI/GListEntry.o ../grom/GromOSAPI/GromOSAPI/GMessage.o ../grom/GromOSAPI/GromOSAPI/GMessageInput.o ../grom/GromOSAPI/GromOSAPI/GMessageStart.o ../grom/GromOSAPI/GromOSAPI/GMessageShowList.o ../grom/GromOSAPI/GromOSAPI/GMessagePickList.o sample.o -lbluetooth -lpthread
	
GromApp.o: ../grom/GromOSAPI/GromOSAPI/GromApp.cpp
	g++ -c -Wall ../grom/GromOSAPI/GromOSAPI/GromApp.cpp

GList.o: ../grom/GromOSAPI/GromOSAPI/GList.cpp
	g++ -c -Wall ../grom/GromOSAPI/GromOSAPI/GList.cpp
	
GListEntry.o: ../grom/GromOSAPI/GromOSAPI/GListEntry.cpp
	g++ -c -Wall ../grom/GromOSAPI/GromOSAPI/GListEntry.cpp
	
GMessage.o: ../grom/GromOSAPI/GromOSAPI/GMessage.cpp
	g++ -c -Wall ../grom/GromOSAPI/GromOSAPI/GMessage.cpp

GMessageInput.o: ../grom/GromOSAPI/GromOSAPI/GMessageInput.cpp
	g++ -c -Wall ../grom/GromOSAPI/GromOSAPI/GMessageInput.cpp
	
GMessageStart.o: ../grom/GromOSAPI/GromOSAPI/GMessageStart.cpp
	g++ -c -Wall ../grom/GromOSAPI/GromOSAPI/GMessageStart.cpp
	
GMessageShowList.o: ../grom/GromOSAPI/GromOSAPI/GMessageShowList.cpp
	g++ -c -Wall ../grom/GromOSAPI/GromOSAPI/GMessageShowList.cpp
	
GMessagePickList.o: ../grom/GromOSAPI/GromOSAPI/GMessagePickList.cpp
	g++ -c -Wall ../grom/GromOSAPI/GromOSAPI/GMessagePickList.cpp
	
sample.o: sample.cpp
	g++ -c -Wall sample.cpp

clean:
	rm -rf *.o
	rm -f *.o ../grom/GromOSAPI/GromOSAPI/
