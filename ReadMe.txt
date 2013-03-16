Automatically prints getters / setters / modifiers for arguments to the terminal.
Usage: mkgset -[flags] -[type] [arg1] [arg2] ... [argn]
Where type is the object to return or set as char[80].

Flags:
	m : Makes a modifier for the argument. arg += mod
	s : Makes a setter for the argument. Note: You will have to replace return type manually
	g : Makes a getter for the argument
	p : Generates a function prototype for others. Will be written before other methods


Flag order does not matter.

It can do multiple varaible types in one line.

Ex: mkgset -s -int rawr roar -long megarawr megaroar

output:
/** Sets rawr with the argument passed in **/
void set_rawr( int set ){ 
	rawr = set;
}

/** Sets roar with the argument passed in **/
void set_roar( int set ){ 
	roar = set;
}

/** Sets megarawr with the argument passed in **/
void set_megarawr( long set ){ 
	megarawr = set;
}

/** Sets megaroar with the argument passed in **/
void set_megaroar( long set ){ 
	megaroar = set;
}

----------------------------------------------

Oh, and helpful tips for those that don't know. Since you may or may not be able to copy from the terminal. You can stick to output to the file.
Ex: mkgset -s -int rawr roar -long megarawr megaroar > test.txt

The output will be stored into test.txt
----------------------------------------------


As for why I created it. As far as I'm aware, VS2012 does not have an auto getter/setter like Ecplise. It will probably help with other languages anyways.


Cheers!

-Xin

