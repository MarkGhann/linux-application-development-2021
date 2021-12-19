# Task 10: I18n

## Cmake
```
cd <build dir>
cmake ..
```

## Build the program `100`, translation and manpage
```
make
```  

## Make the trenslation
```
make translate
```  

## Run the program in russian
```
make ru_100
```  

## Update the trenslation
```
make update_100
```  

## Build manpage
```
make man
```  

## Open manpage
```
make man_goes
```  

## installation
```
make  DESTDIR=<dst dir> install
```  

## default instalation
```
make  DESTDIR=/usr install
```  

## Clean (Delete All Related Files from  Build Directory)
```
make build_clean
```