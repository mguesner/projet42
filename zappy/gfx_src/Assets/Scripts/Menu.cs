using UnityEngine;
using System.Collections;
using System;
using System.IO;
using System.Net;
using System.Text;
using System.Net.Sockets;

public class Menu : MonoBehaviour {

	public static TcpClient tcpc;
	public static  NetworkStream fd;
	// Use this for initialization
	public void save_this(NetworkStream stm)
	{
		fd = stm;
	}
	void Start () {
		DontDestroyOnLoad(transform.gameObject);
	}
}
