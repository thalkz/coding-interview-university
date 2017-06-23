public class Vector {

  private static int MIN_CAPACITY = 16;
  private int size;
  private int[] array;

  public Vector() {
    size = 0;
    array = new int[MIN_CAPACITY];

    for(int i = 0; i < array.length; i++) {
      array[i] = 0;
    }
  }

  public int capacity() {
    return array.length;
  }

  public int size() {
    return size;
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public int at(int index) {
    if (index >= 0 && index < array.length){
      return array[index];
    } else {
      System.out.println("Index out of bound");
      return -1;
    }
  }

  public void push(int item) {
    if(size == array.length) {
      resize(size * 2);
    }
    array[size] = item;
    size++;
  }

  public void insert(int index, int item) {
    if (index >= 0 && index <= size){
      push(item);

      for(int i = size - 1; i > index; i--) {
        ech(i, i - 1);
      }
    } else {
      throw new RuntimeException("Cannot insert item out of bounds");
    }
  }

  public String toString() {
    String result = "Vector = [ ";
    for(int i = 0; i < size; i++) {
      result += array[i] + " ";
    }
    result += "]\n(capacity : " + array.length + ", size : " + size + ")\n";;
    return result;
  }

  public void prepend(int item) {
    insert(0, item);
  }

  public int pop() {
    if (size > 0) {
      if(size <= array.length / 4 && array.length >= MIN_CAPACITY * 2) {
        resize(array.length / 2);
      }

      int temp = array[size - 1];
      array[size - 1] = 0;
      size--;
      return temp;
    } else {
      throw new RuntimeException("Cannot pop empty Vector");
    }
  }

  public int delete(int index) {
    if(index >= 0 && index < size) {
      int deleted = array [index];
      array[index] = 0;
      for(int i = index; i < size; i++) {
        ech(i, i + 1);
      }
      size--;
      return deleted;
    } else {
      throw new RuntimeException("Cannot delete out of bound index");
    }
  }

  public void remove(int item) {
    int index = 0;
    while(index != -1){
      index = find(item);
      if(index != -1) {
        delete(index);
      }
    }
  }

  public int find(int item) {
    for(int i = 0; i < size; i++) {
      if(item == array[i]){
        return i;
      }
    }
    return -1;
  }

  private void ech(int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }

  private void resize(int newCapacity) {
    int[] newArray = new int[newCapacity];
    for(int i = 0; i < size; i++) {
      newArray[i] = array[i];
    }
    for(int i = size; i < newArray.length; i++){
      newArray[i] = 0;
    }
    array = newArray;
  }

  public static void main(String[] args) {
    Vector v = new Vector();

    for(int i = 0; i < 20; i++) {
      v.push(i);
    }

    System.out.println("Vector with 20 elements");
    System.out.println(v.toString());

    v.prepend(200);
    v.insert(5, 100);

    System.out.println("Prepend 200 and add 100 at 5th position");
    System.out.println(v.toString());
    System.out.println("5th element : " + v.at(5) + "\n");

    for(int i = 0; i < 15; i++) {
      v.pop();
    }

    System.out.println("Pop 15 items");
    System.out.println(v.toString());

    v.delete(3);
    System.out.println("Delete 3rd item");
    System.out.println(v.toString());
    System.out.println("Item 100 is at index : " + v.find(100));

    v.prepend(100);
    v.insert(2, 100);
    v.remove(100);
    System.out.println(v.toString());
  }
}
