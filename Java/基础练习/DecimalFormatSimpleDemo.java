import java.text.DecimalFormat;
public class DecimalFormatSimpleDemo {
	//使用实例化对象时设置格式化模式
	static public void SimgleFormat(String pattern,double value) {
		DecimalFormat myFormat = new DecimalFormat();
		String output = myFormat.format(value);
		System.out.println(value+""+pattern+""+output);
	}
	
	//使用applyPattern()方法对数字进行格式化
	static public void UseApplyPatternMethodFormat(String pattern, double value) {
		DecimalFormat myFormat = new DecimalFormat();
		myFormat.applyPattern(pattern);		//调用applyPattern()方法设置格式化模板
		System.out.println(value+""+pattern+""+myFormat.format(value));
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SimgleFormat("###,###,###",123456.789);
		SimgleFormat("000000.###kg",123456.789);
		SimgleFormat("000000.000",123.78);
		
		UseApplyPatternMethodFormat("#.###%",0.789);
		UseApplyPatternMethodFormat("###.##%",123456.789);
		UseApplyPatternMethodFormat("0.00\u2030",0.789);
	}

}
