package com.xlsxtools;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

public class CSVReader {
	private List<String[]> list = new ArrayList<String[]>();// 存储cvs数据
	private AtomicInteger index = new AtomicInteger(-1);// 记录当前索引
	private int rowSize = 0;// 行数
	private int columnSize = 0;// 每行的列数

	/**
	 * 
	 * @param fileName
	 *            :文件路径
	 * @param split
	 *            ：列分隔符
	 * @throws IOException
	 */
	public CSVReader(String fileName, String split) throws IOException {
		load(fileName, 0, 0, split);
	}

	/**
	 * 
	 * @param fileName
	 *            :文件路径
	 * @param startRow
	 *            ：开始行，0开始
	 * @param split
	 *            ：列分隔符
	 * @throws IOException
	 */
	public CSVReader(String fileName, int startRow, String split) throws IOException {
		load(fileName, startRow, 0, split);
	}

	/**
	 * 
	 * @param fileName
	 *            :文件路径
	 * @param startRow
	 *            ：开始行，0开始
	 * @param column
	 *            :指定列数
	 * @param split
	 *            ：列分隔符
	 * @throws IOException
	 */
	public CSVReader(String fileName, int startRow, int column, String split) throws IOException {
		load(fileName, startRow, startRow, split);
	}

	private void load(String fileName, int startRow, int column, String split) throws IOException {
		String separator = System.getProperty("line.separator");
		String crlf = "\r\n";
		String cr = "\r";
		String lf = "\n";
		int startRowReal = startRow;
		if(separator.equalsIgnoreCase(crlf))
		{
			//修复 bufferedReader.readLine()) 按cr ,lf 分行的Bug
			startRowReal = 2*startRow;
		}
			
		BufferedReader bufferedReader = null;
		try {
			bufferedReader = new BufferedReader(new FileReader(fileName));
			String stemp = null;
			int index = 0;
			while ((stemp = bufferedReader.readLine()) != null) {
				index++;
				if (index <= startRowReal)
					continue;
				if(stemp.equalsIgnoreCase(cr) || stemp.equalsIgnoreCase(lf) ||  stemp.isEmpty())
				{
					continue;
				}
				// 如果没有传入列数，则以文件的第一行分割作为列数
				if (column <= 0)
					column = stemp.split(split).length;
				list.add(getRow(stemp, split, column));
			}
			this.rowSize = list.size();
			this.columnSize = list.get(0).length;
		} finally {
			bufferedReader.close();
		}
	}

	// 得到文件的行数
	public int getRowSize() {
		return rowSize;
	}

	// 得到文件的列数
	public int getColumnSize() {
		return columnSize;
	}

	// 是否有下一行记录
	public boolean next() {
		return index.addAndGet(1) < rowSize;
	}

	public int getInt(int i) {
		String value = this.getString(i);
        if(value.length() == 0)
		{
			return 0;
		}
		return Integer.parseInt(value);
	}

	public String getString(int i) {
		return list.get(this.index.get())[i];
	}

	/**
	 * 默认返回yyyy-MM-dd HH:mm:ss格式日期
	 * 
	 * @param i
	 * @return
	 */
	public Date getDate(int i) throws ParseException {
		return this.getDate(i, "yyyy-MM-dd HH:mm:ss");
	}

	public Date getDate(int i, String pattern) throws ParseException {
		String value = this.getString(i);
		if (value == null)
			return null;
		else {
			SimpleDateFormat sdf = new SimpleDateFormat(pattern);
			return sdf.parse(value);
		}
	}

	// 取得指定行的值
	private String[] getRow(String row, String split, int column) {
		if (row == null || "".equals(row.trim()))
			return null;
		String[] cells = row.split(split);

		if (column == cells.length)
			return cells;

		String[] tempCells = new String[column];
		for (int i = 0; i < column; i++) {
			if (i < cells.length)
				tempCells[i] = cells[i];
			else
				tempCells[i] = "";
		}

		return tempCells;
	}
}
