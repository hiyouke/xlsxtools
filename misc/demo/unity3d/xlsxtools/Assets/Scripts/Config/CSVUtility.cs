using System;

public class CSVUtility 
{	
	public static int ToInt(string str)
	{
		try
		{
			return System.Int32.Parse(str);
		}
		catch(System.Exception ex)
		{
			LogError(ex);
			return 0;
		}
	}
	
	public static uint ToUInt(string str)
	{
		try
		{
			return System.UInt32.Parse(str);
		}
		catch(System.Exception ex)
		{
			LogError(ex);
			return 0;
		}
	}

	public static float ToFloat(string str)
	{
		try
		{
			return (float)System.Double.Parse(str);
		}
		catch(System.Exception ex)
		{
			LogError(ex);
			
			return 0;
		}
	}

	public static void LogError(object obj)
	{
	}
}