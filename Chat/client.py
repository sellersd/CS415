##################################################
# Author: David Sellers
# Date: Spring 2022
# CS 415
# Programming Assignment 4
# Chat room using sockets
# Client side program
# Some code retreived from: https://www.techwithtim.net/tutorials/socket-programming/
##################################################
CONN
import socket
import threading

# Constants
s = socket.socket()
PORT = 12346
ENCODING = 'utf8'
DISCONNECT = '!QUIT'.encode(ENCODING)
SIZE = 64
cmd_list = {'CONNECT':'Connects to a server. CONNECT addr',
            'MESSAGE':'Send a message to the server. MESSAGE msg_txt',
            'USERS':'Get a list of all users connected to the server. USERS',
            'DISCONNECT':'Disconnects the user from the server. DISCONNECT'}
def send(msg):
    s.send(msg.encode(ENCODING))

def receive(SIZE):
    print(s.recv(SIZE))

# Code provided by instructor
# modified to Python 3 by student
def connect(server):
    s.connect((server, PORT))

def run_cmd(cmd):
    cmd = cmd.split()
    if cmd[0] == 'h':
        print('List of commands.')
        for c in cmd_list:
            print(c)
    elif cmd[0] == 'MESSAGE':
        send(cmd[1])
    elif cmd[0] == 'CONNECT':
        connect(cmd[1])
    elif cmd[0] == 'USERS':
        send('get_users')
    elif cmd[0] == 'DISCONNECT':
        send(DISCONNECT)
        connected = False
    else:
        print('I do not know how to do that.')
connected = True

# t1 = threading.Thread(target=send, args=(m))
# t2 = threading.Thread(target=receive, args=(SIZE))
# t1.start()
# t2.start()
cmd = input('(h for help) >>')
run_cmd(cmd)

while connected:
    cmd = input('(h for help) >>')
    run_cmd(cmd)
    receive(SIZE)

s.close()
