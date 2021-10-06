<h1>Simple client/server application using UNIX signals</h1>
<p>It is required to create a communication program in the form of a client and a server. The server should be started first, and once started, it should display its PID. The client accepts as parameters the PID server with a string to be sent. After receiving the string, the server should display it. Communication is done using UNIX signals only. Only the two signals SIGUSR1 and SIGUSR2 can be used. This project is implemented for an operating system based on the Linux kernel.</p>
<h3>How to use it</h3>
<p>Simply run the setup script :</p>
<pre>
<code>make</code>
</pre>
<pre>
<code>./server</code>
</pre>
<br>
<br>
<p>And in another terminal window :</p>
<pre>
<code>./client [server_pid] [value]</code>
</pre>

