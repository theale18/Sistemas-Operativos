using System; 
using System.Net; 
using System.Net.Sockets; 
using System.Text; 
 
class Server 
{ 
    static void Main() 
    { 
        TcpListener server = new TcpListener(IPAddress.Any, 5000); 
        server.Start(); 
        Console.WriteLine("Servidor iniciado. Esperando conexión..."); 
        while (true) 
        { 
            using (TcpClient client = server.AcceptTcpClient()) 
            using (NetworkStream stream = client.GetStream()) 
            { 
                byte[] buffer = Encoding.UTF8.GetBytes("¡Hola, 
Cliente!"); 
                stream.Write(buffer, 0, buffer.Length); 
                Console.WriteLine("Mensaje enviado al cliente."); 
            } 
        } 
    } 
} 
