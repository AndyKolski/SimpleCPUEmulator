make: clean emulator createrom
	echo 'Finished'

emulator:
	echo 'compiling emulator.c ...'
	gcc ./src/emulator.c -o emulator
	echo 'done'
createrom:
	echo 'compiling createrom.c ...'
	gcc ./src/createrom.c -o createrom
	echo 'done'
clean:
	-rm createrom
	-rm emulator