using UnityEngine;
using System.Collections;
using System;
using System.IO;
using System.Net;
using System.Text;
using System.Net.Sockets;

public class Networkstuff : MonoBehaviour {

	public string IP_value = "e1r11p1";
	public string port_value = "666";
	public static TcpClient tcpclnt;
	public static NetworkStream stm;

	public void OnGUI()
	{
		IP_value = GUI.TextField(new Rect(Screen.width / 2, Screen.height / 3, 200, 20), IP_value, 25);
		port_value = GUI.TextField(new Rect((Screen.width / 2), (Screen.height / 3) + 22, 200, 20), port_value, 25);
		if (GUI.Button (new Rect ((Screen.width / 2), (Screen.height / 3) + 42, 70f, 20f), "Connect") || Input.GetKey(KeyCode.Return))
		{
			tcpclnt = new TcpClient ();
			Menu save = new Menu();
			GUI.Box (new Rect (Screen.width / 2, Screen.height / 3,100,50), "Connecting.....");
			tcpclnt.Connect(IP_value, int.Parse (port_value));
			byte[] buffer = System.Text.Encoding.ASCII.GetBytes ("__GFX__\n");
			stm = new NetworkStream(tcpclnt.Client , true);
			stm.Write (buffer, 0, buffer.Length);
			save.save_this(stm);
			Application.LoadLevel ("after_connect");
		}
	}
	static public TcpClient get_tcpc()
	{
				return (tcpclnt);
		}
	void	Update()
	{
		if (Input.GetKey(KeyCode.Escape))
		{
			Application.Quit();
		}
	}
}
