import sys
import os
import subprocess
import random
import operator
import csv
import logging
import tempfile

def run_command(command):
    print('----------------------------------------')
    print('Executing: '+command)
    pipe = subprocess.Popen(command, shell=True, bufsize=1, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, universal_newlines=True)
    #pipe.stdout.close()
    out, err = pipe.communicate()
    print (out)
    

# 0_script 1_list_of_student_usernames 2_directory_to_store_files
# SAMPLE: compile_script.py level_of_compilation
print ("Number of arguments: %d" %  len(sys.argv))
print ("Argument List: %s" % str(sys.argv))

files_to_compile = ['main', 'lib\hd44780','lib\I2C','lib\MPU6050']
file_to_compile = 'main'
if len(sys.argv) == 2:
    com_port = 'com4'
else:
	com_port = sys.argv[2]

level_of_compilation = int(sys.argv[1])

path_win_avr = 'C:/Users/10275/AVRGNU/avr8-gnu-toolchain/bin/'

if level_of_compilation >= 1: 
    for fs in files_to_compile:
        cmd = path_win_avr + 'avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o'+fs+'.o '+fs+'.c'
        run_command(cmd)
    
if level_of_compilation >= 2:
    cmd = path_win_avr + 'avr-gcc -mmcu=atmega328p '
    for fs in files_to_compile:
        cmd = cmd+fs+'.o ' 
    cmd = cmd +'-o '+file_to_compile
    run_command(cmd)

if level_of_compilation >= 3:
    cmd = path_win_avr + 'avr-objcopy -O ihex -R .eeprom '+file_to_compile+' '+file_to_compile+'.hex'
    run_command(cmd)

if level_of_compilation >= 4:
    cmd = path_win_avr + 'avrdude -patmega328p -P'+com_port+' -carduino -D -U flash:w:'+file_to_compile+'.hex:i'
    run_command(cmd)
