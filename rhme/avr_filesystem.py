import serial		# For interacting with the Arduino board
import hashpumpy	# For performing length extension attack

# Connecting to the Arduino board
ser = serial.Serial("/dev/ttyUSB0", 19200, timeout=0.1)

# Function to read the response from the Arduino board
def _read():
	output = ''
	while ">>" not in output:
		output += ser.read(1000)
	return output

# Assuming the keylength lies between 1-20
for key_len in range(1,20):
	hash,message = hashpumpy.hashpump('96103df3b928d9edc5a103d690639c94628824f5', 'cat.txt', ':passwd', key_len)
	
	print "Key Length : " + str(key_len) + " Message : " + str(message) + " Hash : " + str(hash)

	ser.write(hash + "#" + message + "\r\n")
	print _read()

#ser.close()
