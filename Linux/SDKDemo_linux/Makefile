###########################################################################
CXX=g++ 
CC=$(CXX)
###########################################################################
DIR:=.
OBJECT:=../bin/sdkdemo
SOURCES:=$(wildcard $(DIR)/project/source/*.cpp)

DELETE:=$(patsubst %.cpp,%.o,$(SOURCES))
DELETE+=$(patsubst %.cpp,%.d,$(SOURCES))

override CXXFLAGS+=-D__ENVIRONMENT_LINUX__ -g
override CXXFLAGS+=-I$(DIR)/project/include
override CXXFLAGS+=-I$(DIR)/../../include
override CFLAGS+=$(CXXFLAGS)
override LDFLAGS+=-rdynamic
override MAKEFLAGS += -s
############################################################################
$(OBJECT):$(patsubst %.cpp,%.o,$(SOURCES))
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^ -lrt -lpthread -I,-Bdynamic -L../bin -ldvrnetsdk -lasound
###########################################################################
%.d:%.cpp
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(SOURCES:.cpp=.d)
###########################################################################
.PHONY:clean
clean:
	rm $(DELETE) -f
	rm $(OBJECT) -f
