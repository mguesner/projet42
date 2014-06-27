using UnityEngine;
using System.Collections;

public class Cam_move : MonoBehaviour
{
	public int LevelArea = 100;

	public int ScrollArea = 250;
	public int ScrollSpeed = 25;
	public int DragSpeed = 100;

	public int ZoomSpeed = 25;
	public int ZoomMin = 20;
	public int ZoomMax = 1000;

	public int PanSpeed = 50;
	public int PanAngleMin = 25;
	public int PanAngleMax = 50;

	// Update is called once per frame
	void Update()
	{
		var translation = Vector3.zero;

		var zoomDelta = Input.GetAxis("Mouse ScrollWheel")*ZoomSpeed*Time.deltaTime;
		if (zoomDelta!=0)
		{
			translation -= Vector3.up * ZoomSpeed * zoomDelta;
		}
		var pan = camera.transform.eulerAngles.x - zoomDelta * PanSpeed;
		pan = Mathf.Clamp(pan, PanAngleMin, PanAngleMax);
		if (zoomDelta < 0 || camera.transform.position.y < (ZoomMax / 2))
		{
			camera.transform.eulerAngles = new Vector3(pan, 0, 0);
		}
		translation += new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));
		if (Input.GetMouseButton(2))
		{
			translation -= new Vector3(Input.GetAxis("Mouse X") * DragSpeed * Time.deltaTime, 0,
			                           Input.GetAxis("Mouse Y") * DragSpeed * Time.deltaTime);
		}
		var desiredPosition = camera.transform.position + translation;
		if (desiredPosition.x < -LevelArea || LevelArea < desiredPosition.x)
		{
			translation.x = 0;
		}
		if (desiredPosition.y < ZoomMin || ZoomMax < desiredPosition.y)
		{
			translation.y = 0;
		}
		if (desiredPosition.z < -LevelArea || LevelArea < desiredPosition.z)
		{
			translation.z = 0;
		}
		camera.transform.position += translation;
	}
}
