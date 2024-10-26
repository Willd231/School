import socket

# Define the server's host and port (same as the server)
SERVER_HOST = 'eustis3.eecs.ucf.edu'
SERVER_PORT = 5001

def run_client():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((SERVER_HOST, SERVER_PORT))
        print(f"Connected with server on {SERVER_HOST}")

        while True:
            # Get input from the user
            question = input("Enter math question (e.g., 20+10.5=): ")

            # Send the question to the server
            client_socket.sendall(question.encode())

            # If the question is "0/0=", exit the loop and close connection
            if question.strip() == "0/0=":
                print("User input ends; end the client program")
                break

            # Receive and print the server's response
            response = client_socket.recv(1024).decode()
            print(f"Answer from server: {response}")

if __name__ == "__main__":
    run_client()
