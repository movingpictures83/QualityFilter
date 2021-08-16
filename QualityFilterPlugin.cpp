#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "QualityFilterPlugin.h"

void QualityFilterPlugin::input(std::string file) {
 inputfile = file;
 /*std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }*/
}

void QualityFilterPlugin::run() {
   
}

void QualityFilterPlugin::output(std::string file) { 
	   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";

   command += "qiime quality-filter q-score --i-demux "+inputfile+" --o-filtered-sequences "+file+"-filtered.qza --o-filter-stats "+file+"-filter-stats.qza; ";

   command += "conda deactivate; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";



 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<QualityFilterPlugin> QualityFilterPluginProxy = PluginProxy<QualityFilterPlugin>("QualityFilter", PluginManager::getInstance());
