

public class InnerClass {

	private int defaultAge = 5;
	public void addAge( int age){
		class NewAge{
			private int getAge(){
				return age + defaultAge;
			}
		}

		NewAge newAge = new NewAge();
		System.out.print(newAge.getAge());
	}

	public static void main(String[] args) {
		InnerClass innerClass = new InnerClass();
		innerClass.addAge(8);
	}
}
