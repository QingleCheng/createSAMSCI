# createSAMSCI
Create input file for regional SCI computation based on the SimCenter Workflow


##input file

exampleBIM.json exampleEVENT.json exampleSAM.json


using this command to run the program:

    createSCISAM.exe exampleBIM.json exampleEVENT.json exampleSAM.json exampleSAMSCI.txt



##Output file

exampleSAMSCI.txt


NOTE: the applications require the jansson lib be installed. jansson is 
a free BSD lib recomended online for dealing with reading/writing json files.
It is assumed installed in /usr/local/jansson as seen in Makefiles.


