import subprocess
import random
import string

def generate_random_string(length):
	characters = string.ascii_letters + string.digits
	return ''.join(random.choice(characters) for _ in range(length))

# Function to execute client with given input
def execute_client_and_wait(pid_server, input_str):
	subprocess.run(['./client', str(pid_server), input_str], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

# Function to check if given input is present in the file
def check_input_in_file(input_str, log_file):
	with open(log_file, 'r') as f:
		return input_str in f.read()
# Function to start the server and return its PID
def start_server():
	log_file = 'server_output.log'
	return subprocess.Popen(['./server'], stdout=open(log_file, 'w'), stderr=subprocess.DEVNULL).pid

def kill_server(pid):
	try:
		subprocess.Popen(['kill', '-9', str(pid)])
		# print(f"Process with PID {pid} killed.")
	except Exception as e:
		print(f"Error: {e}")

# Main function
def main():
	pid_server = start_server()
	# print(f"Server started with PID: {pid_server}")

	log_file = 'server_output.log'  # Path to the log file

	input_lengths = [10, 100, 1000, 5000]
	for length in input_lengths:
		print(f"Testing with {length}")
		print(f"-------------------")
		for _ in range(10):
			input_str = generate_random_string(length)
			execute_client_and_wait(pid_server, input_str)
			if check_input_in_file(input_str, log_file):
				print(f"\033[1;32m[OK] \033[0m", end='', flush=True)
			else:
				print(f"\033[0;31m[KO] \033[0m", end='', flush=True)
		print(f"\n-------------------")
	
	kill_server(pid_server)

if __name__ == "__main__":
	main()
