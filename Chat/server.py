
##################################################
# Author: David Sellers
# Date: Spring 2022
# CS 415
# Programming Assignment 4
# Chat room using sockets
# Some code retreived from: https://www.techwithtim.net/tutorials/socket-programming/
##################################################

import socket
import threading
import random
import pickle

# Constants
PORT = 12346
ENCODING = 'utf8'
DISCONNECT = '!QUIT'.encode(ENCODING)
SIZE = 64


# Code provided by instructor
# modified to Python 3 by student
s = socket.socket()
print("Socket successfully created: ", s)

# port = random.randint(10000,20000)
s.bind(('', PORT))
print("socket bound to: %s" % PORT)

s.listen(5)
print("Socket is listening...")

users_connected = []

def send_msg(conn, addr, msg):

    # msg_length = len(msg)
    # send_length = str(msg_length).encode(ENCODING)
    # send_length += b' ' * (SIZE - len(send_length))

    for user in users_connected:
        # user[0].send(msg.encode(ENCODING))
        user[0].send(msg.encode(ENCODING))

def client_conn(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected.")

    connected = True
    # b"" means convert string to byte stream
    welcome_message = f"Thank you for connecting. You are {addr}."
    conn.send(bytes(welcome_message, ENCODING))
    while connected:

        msg = conn.recv(SIZE).decode(ENCODING)
        print(f"[{addr}] {msg}")
        if msg == 'get_users'.encode(ENCODING):
            conn.send(pickle.dumps(users_connected))
        elif msg == DISCONNECT:
            send_msg(conn, addr, f'User {addr} has left the building.')
            connected = False
            
        else:
            send_msg(conn, addr, msg)

    print(f"[CLOSING CONNECTION] {addr}")
    conn.close()
    print(f"[ACTIVE CONNECTIONS] {threading.active_count() -1}")


threads = []

while True:
    conn, addr = s.accept()
    thread = threading.Thread(target=client_conn,args=(conn, addr))
    users_connected.append((conn, addr))
    # print(thread)

    # print(users_connected)

    thread.start()

    threads.append(thread)
    print(f"[ACTIVE CONNECTIONS] {threading.active_count() -1}")
    # print("Got connection from ", addr)
#
#
    # conn.close()
