using UnityEngine;
using System.Collections;
using System.IO;
using System.Collections.Generic;

public class RowHelper
{
	string[] rows;
	int 	 idx;
	
	public RowHelper(string[] rs)
	{
		rows = rs;
		idx = 0;
	}
	
	public string Read()
	{
		return rows[idx++];
	}
}

public class CSVReader
{
	const int MaxColumn = 128;

	public struct FieldData
	{
		public string[] FieldText;
    }
	
	private List<FieldData> items = new List<FieldData>();
	private int columnCount = 0;

	TextAsset LoadTextAsset(string file)
	{
		TextAsset textAsset = null;
		int tLen = file.Length;
		if (tLen > 4 && file[tLen - 4] == '.')
		{
			string subFile = file.Substring(0, tLen - 4);
			textAsset = Resources.Load(subFile) as TextAsset;
		}
		else
		{
			textAsset = Resources.Load(file) as TextAsset;
		}
		
		return textAsset;
	}

	public bool LoadText(string textfileName, int skinLine)
	{
		TextAsset textAsset =LoadTextAsset(textfileName);
		string strText = textAsset.text;
		if(strText == null)
		{
			Debug.LogError("Load text file " + textfileName + " failed !");

			return false;
		}

		string[] lines = strText.Split(new char[]{'\n'});
	    int iStartLine = Mathf.Max(0, skinLine);

		for(int i = iStartLine; i < lines.Length; i++)
		{
			ParseLine(lines[i]);
		}

		return true;
	}
	
	public string GetString(int iRow, int iColumn)
	{
		if(iRow < 0 || iRow >items.Count)
		{
			return "";
		}

		if(iColumn < 0 || iColumn > GetColumnCount())
		{
			return "";
		}
			
		return items[iRow].FieldText[iColumn];
	}
	
	public int FindRowIndex(string key, int iFieldIndex)
	{
		for(int i = 0; i < items.Count; i++)
		{
			if(items[i].FieldText[iFieldIndex] == key)
			{
				return i;
			}
		}

		return -1;
	}

	public int GetColumnCount() { return columnCount; }
	public int GetRowCount()    { return items.Count; }
	
	public string[]	GetRow(int idx)
	{
		return items[idx].FieldText;
	}

	private void ParseLine(string lineText)
	{
		string[] vals  = lineText.Split(new char[]{'#'});
		FieldData item = new FieldData();
		item.FieldText = new string[MaxColumn];

		if(columnCount == 0)
		{
			columnCount = vals.Length;

			//empty table
			if(columnCount <= 1)
			{
				return;
			}
		}

		if(columnCount == vals.Length)
		{
			for(int i = 0; i < vals.Length; i++)
		    {
		    	item.FieldText[i] = vals[i].Trim();
		    }

			items.Add(item);
		}
	}
}
