##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CountTo24_uHDL
ConfigurationName      :=Debug
WorkspacePath          := "D:\Projekti\CodeLite\Arduino"
ProjectPath            := "D:\Projekti\CodeLite\Arduino\CountTo24_uHDL"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=hr1uz087
Date                   :=02/03/15
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe 
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="CountTo24_uHDL.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe 
CC       := C:/MinGW-4.8.1/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/ArduinoTB.cpp$(ObjectSuffix) $(IntermediateDirectory)/uHDL.cpp$(ObjectSuffix) $(IntermediateDirectory)/CountTo24_uHDL.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ArduinoTB.cpp$(ObjectSuffix): ArduinoTB.cpp $(IntermediateDirectory)/ArduinoTB.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projekti/CodeLite/Arduino/CountTo24_uHDL/ArduinoTB.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ArduinoTB.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ArduinoTB.cpp$(DependSuffix): ArduinoTB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ArduinoTB.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ArduinoTB.cpp$(DependSuffix) -MM "ArduinoTB.cpp"

$(IntermediateDirectory)/ArduinoTB.cpp$(PreprocessSuffix): ArduinoTB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ArduinoTB.cpp$(PreprocessSuffix) "ArduinoTB.cpp"

$(IntermediateDirectory)/uHDL.cpp$(ObjectSuffix): uHDL.cpp $(IntermediateDirectory)/uHDL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projekti/CodeLite/Arduino/CountTo24_uHDL/uHDL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/uHDL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/uHDL.cpp$(DependSuffix): uHDL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/uHDL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/uHDL.cpp$(DependSuffix) -MM "uHDL.cpp"

$(IntermediateDirectory)/uHDL.cpp$(PreprocessSuffix): uHDL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/uHDL.cpp$(PreprocessSuffix) "uHDL.cpp"

$(IntermediateDirectory)/CountTo24_uHDL.cpp$(ObjectSuffix): CountTo24_uHDL.cpp $(IntermediateDirectory)/CountTo24_uHDL.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Projekti/CodeLite/Arduino/CountTo24_uHDL/CountTo24_uHDL.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CountTo24_uHDL.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CountTo24_uHDL.cpp$(DependSuffix): CountTo24_uHDL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CountTo24_uHDL.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CountTo24_uHDL.cpp$(DependSuffix) -MM "CountTo24_uHDL.cpp"

$(IntermediateDirectory)/CountTo24_uHDL.cpp$(PreprocessSuffix): CountTo24_uHDL.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CountTo24_uHDL.cpp$(PreprocessSuffix) "CountTo24_uHDL.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/CountTo24_uHDL"


