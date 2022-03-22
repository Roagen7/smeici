#!/bin/sh

# Author           : Dominik Lau ( harek2388@gmail.com )
# Created On       : 22.03.2022
# Version          : wersja
#
# Description      : tool that automates parsing movie links from cda.pl to mpv
#
# Licensed under GPL (see /usr/share/common-licenses/GPL for more details
# or contact # the Free Software Foundation for a copy)



#--------------------------------------CONFIG

WEBSITE="https://www.cda.pl"
PLAYER="mpv"

#----------------------------------END CONFIG


playbackMenu(){

    clear

}


searchMenu(){

    read -p $'\e[36m[Search for a video] \e[0m' NAME


    parseSearch $NAME


    #show menu
    for i in "${!TITLES[@]}"; do
        printf "\e[31m$i)\e[0m ${TITLES[i]} \n"
    done


    read -p $'\e[36m[Select choice(b for back)] \e[0m' CHOICE
    
    LINK="$WEBSITE${LINKS[CHOICE]}"

    mpv $LINK &
    playbackMenu
   
}

parseSearch(){

    SEARCH=$(printf '%s' "$1" | tr ' ' '-' ) #sanitize input
    LINK="$WEBSITE/info/$NAME"


    #get list of titles

    TEMP=$(mktemp)
    

    curl -s $LINK | grep -e 'a class="link-title-visit" href="/video/' > $TEMP

    readarray -t <<< $(cat $TEMP | sed -rn 's/.*href="([^"]*)".*/\1/p') LINKS
    readarray -t <<< $(cat $TEMP | sed 's/<[^>]*>//g') TITLES


}



searchMenu 

