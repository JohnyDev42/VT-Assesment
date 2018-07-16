import telnetlib
import sys

def telnet_connect():
	tn = telnetlib.Telnet("linuxzoo.net")
	tn.read_until("login: ")
	tn.write("root"+"\n")
	tn.read_until("Password: ")
	tn.write("secure"+"\n")
	tn.read_until("# ")

	return tn

def get_cmd_op(command=None):
	tn = telnet_connect()
	tn.write(command+"\n")
	data = tn.read_until("# ")

	for line in data.split("\n"):
		print line

if __name__ == "__main__":
	get_cmd_op(sys.argv[1])
