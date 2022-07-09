#!/bin/sh


ifconfig -a | grep -w "ether" | awk -F "ether" '{print $2}' | sed 's/ //g' 
