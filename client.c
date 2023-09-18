// client.c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	pid_t			client_pid;
	union sigval	sigdata;
	int				signal_ammount = atoi(argv[1]);

	pid_t server_pid;

	client_pid = getpid();
	printf("Client PID: %d\n", client_pid);
	printf("Enter the server's PID: ");
	scanf("%d", &server_pid);
	// Create a SIGUSR1 signal containing the client's PID and send it to the server
	sigdata.sival_int = client_pid;
	for (int i = 0; i < signal_ammount; i++)
	{
		if (sigqueue(server_pid, SIGUSR1, sigdata) == -1)
		{
			perror("Signal sending failed");
			exit(EXIT_FAILURE);
		}
		usleep(150);
	}
	printf("Sent %d SIGUSR1 signals to the server (PID %d)\n", signal_ammount, server_pid);
	return (0);
}
