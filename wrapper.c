#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif


#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

#ifdef __linux
#include <unistd.h>
#elif __unix // all unices not caught above
#include <unistd.h>
#elif __posix
#include <unistd.h>
#elif __FreeBSD__
#include <unistd.h>
#elif __sun
#include <unistd.h>
#endif

void get_main_binary_path(char* path, int path_size){
//###########  WINDOW  ##################
#ifdef _WIN64
GetModuleFileName(NULL, path, path_size);
#elif _WIN32
GetModuleFileName(NULL, path, path_size);
//#######################################

//############  APPLE  ##################
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR
        // define something for simulator   
    #elif TARGET_OS_IPHONE
        // define something for iphone  
#else
#define TARGET_OS_OSX 1
if (_NSGetExecutablePath(path, &path_size) == 0){ printf("executable path is %s\n", path); }
else{ printf("buffer too small; need size %u\n", path_size); }
#endif
//#######################################


//############  LINUX  ##################
#elif __linux
readlink("/proc/self/exe", path, path_size); // Linux
#elif __unix // all unices not caught above
readlink("/proc/self/exe", path, path_size); // Linux
#elif __posix
readlink("/proc/self/exe", path, path_size); // Linux
#elif __FreeBSD__
readlink("/proc/curproc/file", path, path_size); // FreeBSD
#elif __sun
readlink("/proc/self/path/a.out", path, path_size); // Solaris
#endif
//#######################################
return;
}
 


int main(){
char path[1024];
int path_size = 1024;
memset(path, 0x00, path_size);

get_main_binary_path(path, path_size);
for(int a = path_size - 1; a >= 0; --a){
if(path[a] == 0){ continue; }
if(path[a] != '/'){ path[a] = 0; }
else{ break; }
}

printf("%s \n", path);

chdir(path);
// missing window cd and mac cd

system("chmod +x ./run.sh 2>/dev/null"); // Ignore error if already executable
int result = system("./run.sh");

if (result == -1){ perror("Error executing script"); return 1; }

return 0;
}
