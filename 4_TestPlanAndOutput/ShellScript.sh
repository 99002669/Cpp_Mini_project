#!/bin/bash
OLDIFS=$IFS
touch ShellReport.csv
mydirectory="$(pwd)"
echo "User-Name,EId,Repo-link,Git-clone status,Build-status,Valgrind,cppcheck" >>"$mydirectory"/ShellReport.csv
while IFS="," read  Name EmailID Repolink; do 

	echo "$Name $EmailID $Repolink" 
	
	git clone $Repolink >>"$mydirectory"/gitclone.txt
	if [ $? -eq 0 ];then
  		echo -n "$Name,$EmailID,$Repolink,Pass," >>"$mydirectory"/ShellReport.csv
  		
 	else 
 		echo -n "$Name,$EmailID,$Repolink,Fail," >>"$mydirectory"/ShellReport.csv
	fi

	repo="$(cut -d"/" -f5 <<<"$Repolink")"
	repofull="$(cut -d"." -f1 <<<"$repo")"
	echo "my pwd is: $mydirectory" 
	echo "my repository is :$repofull"
	cd "$mydirectory"/"$repofull"
	
	make >> "$mydirectory"/make.txt
	
	if [ $? -eq 0 ]; then
  		echo  -n "Build Success," >>"$mydirectory"/ShellReport.csv
  		
 	else 
 		echo -n "Build Failed," >>"$mydirectory"/ShellReport.csv
	fi
	
	
	
       valgrind ./*.out >"$mydirectory"/valgrind.txt 2>&1
       lastline="$( tail -n 1 "$mydirectory"/valgrind.txt)"
       errors="$(cut -d" " -f4 <<<"$lastline")"
       echo -n "$errors," >>"$mydirectory"/Results.csv

       cppcheck *.c* >"$mydirectory"/cppreport.txt 2>&1
       echo "$(grep -o 'error' "$mydirectory"/cppreport.txt| wc -l)" >>"$mydirectory"/ShellReport.csv
	
       cd "$mydirectory" 
       IFS=$OLDFIS
 	
done<$1

 
 
 

