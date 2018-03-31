obj-m += match_target.o
default:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) modules
clean:
	rm -rf *.o *.ko
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) clean
