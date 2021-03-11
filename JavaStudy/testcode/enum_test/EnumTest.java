

public class EnumTest {
	enum EnumT {
		FIRST,
		SECOND,
		THIRD
	}
	public static void main() {
	
		EnumT t = EnumT.FIRST;
		
		switch(t) {
			case FIRST:
				break;
			case SECOND:
				break;
			case THIRD:
				break;
		}
	
	}
}