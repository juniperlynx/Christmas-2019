help:
	@echo 'Help details:'
	@echo 'hex: compile hex file'
	@echo 'flash: install hex file'
	@echo 'program: compile hex and install'

hex:
	avr-gcc -Os -mmcu=attiny84 -c christmascard.c
	avr-gcc -mmcu=attiny84 -o christmascard.elf christmascard.o
	avr-objcopy -O ihex christmascard.elf christmascard.hex

flash:
	avrdude -c usbtiny -p attiny84 -U flash:w:christmascard.hex

