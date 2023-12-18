# python3 sctp client

import socket
import sys
import time
import os
import random
import string
import sctp # install using pip3 install sctp
import threading
import struct #

# global variables
server_ip = '127.0.0.1'
server_port = 7654

# create a socket
sock = sctp.sctpsocket_tcp(socket.AF_INET)
# connect to server
sock.connect((server_ip, server_port))
# set socket timeout
sock.settimeout(10)

# send data to server
def send_data():
    while True:
        try:
            data = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(10))
            length = len(data)
            little_endian_with_unsigned_long_long = "<Q"
            data_to_send = struct.pack(little_endian_with_unsigned_long_long, length)
            sock.sendall(data_to_send)

            sock.sctp_send(bytes(data, 'utf-8'))
            time.sleep(1)
        except socket.timeout:
            print('Socket timeout')
            break
        except:
            print('Error sending data')
            break

# receive data from server
def receive_data():
    while True:
        try:
            # receive data from server
            data = sock.recv(1024)
            # print received data
            print('Received: ' + data.decode('utf-8'))
        except socket.timeout:
            print('Socket timeout')
            break
        except:
            print('Error receiving data')
            break


# create threads
send_thread = threading.Thread(target=send_data)
receive_thread = threading.Thread(target=receive_data)

# start threads
send_thread.start()
receive_thread.start()

# wait for threads to finish
send_thread.join()
receive_thread.join()

# close socket
sock.close()
