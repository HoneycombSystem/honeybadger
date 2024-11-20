import socket
import sys
import time
import os
import random
import string
import sctp # install using pip3 install sctp
import threading
import struct

server_ip = '127.0.0.1'
server_port = 2137


sockets = []
for i in range(5):
    sock = sctp.sctpsocket_tcp(socket.AF_INET)
    sock.connect((server_ip, server_port))
    sock.settimeout(10)
    sockets.append(sock)

def send_data(sock):
    try:
        data = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(12))
        # length = len(data)
        # little_endian_with_unsigned_long_long = "<Q"
        # data_to_send = struct.pack(little_endian_with_unsigned_long_long, length)
        # sock.sendall(data_to_send)

        #sock.sctp_send(bytes(data, 'utf-8'))
        sock.sctp_send(str.encode(data))
        print('Sent: ' + data)
        name = sock.recv(1024) # This might be a problem for someone with a reaaallly long name.
        name = name.strip()
        print('Received: ' + name.decode('utf-8'))
    except socket.timeout:
        print('Socket timeout')
    except:
        print('Error sending data')

send_threads = []

for sock in sockets:
    send_thread = threading.Thread(target=send_data, args=(sock,))
    send_thread.start()
    send_threads.append(send_thread)

for send_thread in send_threads:
    send_thread.join()

for sock in sockets:
    sock.close()

