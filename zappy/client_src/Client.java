import java.io.IOException;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;
class Client
{
	public static void main(String[] args) throws IOException
	{
		int				port;
		SocketChannel	socketChannel = SocketChannel.open();
		Opt				option = new Opt(args);
		ByteBuffer r_buf = ByteBuffer.allocate(4096);
		ByteBuffer w_buf = ByteBuffer.allocate(4096);
		int bytesRead;
		String s = "";
		String s2;
		Drone d = new Drone(option.getname(), option);

		socketChannel.connect(new InetSocketAddress(option.getdomain(), option.getport()));
		System.out.println("done");
		while (true)
		{
				if ((bytesRead = socketChannel.read(r_buf)) == -1)
					System.exit(0);
				r_buf.flip();
				Charset def = Charset.defaultCharset() ;
				Charset cs = Charset.forName("ASCII");
				CharBuffer cb = cs.decode(r_buf);
				r_buf.clear();
				s = s + cb.toString();
				if (s.indexOf('\n') != -1)
				{
					s2 = s.substring(0, s.lastIndexOf('\n'));
					s = s.substring(s.lastIndexOf('\n') + 1);
					String[] tab = s2.split("\n");
					for (String str : tab)
					{

						if (str.startsWith("team"))
							System.out.println(str);
						else if (d.isConnect() && !str.matches("[0-9]+ [0-9]+"))
						{
							if (d.answer(str))
								w_buf = d.getAction();
						}
						else if (str.equals("BIENVENUE"))
						{
							w_buf = def.encode(option.getname()+"\n");
						}
						else if (str.matches("[0-9]+") && Integer.parseInt(str) > 0)
						{
							int n = 5;
							d.connect();
							w_buf = d.getAction();
						}
					}
				}
			if (w_buf.hasRemaining())
				socketChannel.write(w_buf);
		}
	}
}
