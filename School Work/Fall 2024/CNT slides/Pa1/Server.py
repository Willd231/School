import socket

# Define the server's host and port
HOST = '0.0.0.0'  # Listen on all available interfaces
PORT = 5001  # Choose a port number greater than 1024

def process_question(question):
    try:
        # Remove the '=' sign
        question = question.strip('=')

        # Evaluate the math expression
        result = eval(question)
        return str(result)
    except Exception:
        return "Input error. Re-type the math question again."

def run_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((HOST, PORT))
        server_socket.listen()
        print(f"Server running on {HOST}:{PORT}, waiting for a client to connect...")

        conn, addr = server_socket.accept()
        with conn:
            print(f"Connected by client on {addr}")
            while True:
                data = conn.recv(1024).decode()
                if not data:
                    break
                print(f"Received question: {data}")
                if data.strip() == "0/0=":
                    print("Received '0/0='; end the server program")
                    break

                # Process the question and send the result
                response = process_question(data)
                conn.sendall(response.encode())

if __name__ == "__main__":
    run_server()
