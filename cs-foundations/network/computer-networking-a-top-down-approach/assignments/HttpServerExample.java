import java.net.*;
import java.io.*;
import java.util.Date;

public class HttpServerExample
{
	private ServerSocket serverSocket;
    private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;
	private String response = "HTTP/1.1 200 Connection established\r\n" + 
							  "Content-Type: text/html; charset=utf-8\r\n" + 
							  "\r\n" + 
							  "hello client!";
    public void start(int port) throws Exception {
        serverSocket = new ServerSocket(port);
		System.out.println("Socket server start...");
        while (true) {
            Socket clientSocket = serverSocket.accept();
			System.out.println("Socket server accept...");
            InputStreamReader isr =  new InputStreamReader(clientSocket.getInputStream());
            BufferedReader reader = new BufferedReader(isr);
            String line = reader.readLine(); 
			
			System.out.println();
            while (!line.isEmpty()) {
                System.out.println(line);
                line = reader.readLine();
            }
			
			out = new PrintWriter(clientSocket.getOutputStream(), true);
			out.println(response + " " + new Date());
			out.close();
        }
    }
 
    public void stop() throws Exception{
        in.close();
        out.close();
        clientSocket.close();
        serverSocket.close();
    }
    public static void main(String[] args)  throws Exception{
        HttpServerExample server=new HttpServerExample();
        server.start(9000);
    }
	
}