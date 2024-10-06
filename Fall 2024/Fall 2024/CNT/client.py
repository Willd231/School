#!/usr/bin/python
import socket

# define server address and port
HOST = 'eustis3.eecs.ucf.edu'
PORT = 5500

# create socket
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    print(f"Connected to server at {HOST}:{PORT}")

    while True:
        question = input("Enter math question: ")

        #make  sure the format is correct 
        if "=" not in question or not any(op in question for op in ['+', '-', '*', '/']):
            print("Input error. Re-type the math question again.")
            continue

        # send question to the server
        s.sendall(question.encode())

        #  end condition
        if question == "0/0=":
            print("Ending client program.")
            break

        #display the result
        data = s.recv(1024).decode()
        print(f"Answer from server: {data}")

~                                                                                                                                                                                             
~                                                         