# -C-find-binary-own-directory-logic
```txt
##########################
###      DES           ###
##########################
The logic is simple, when you compile a binary, for example this code currently work well on most linux,
it will self change directory to current directory of binary and call the "run.sh" script.

##########################
###      REASON        ###
##########################
To make easy of app dev for portable apps and to make running script easier with GUI click, not open a terminal
every single time you want to run a script.

Also those who may use this can only scrap part of the code for their program.

##########################
###      TODO          ###
##########################
1/ REQ testers for window and macos, those who have experience, I want this repo to be a good place for everyone
to get this logic
2/ Some small code cleaup.
```
