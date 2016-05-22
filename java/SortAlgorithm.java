public class SortAlgorithm{

	//堆排序，begin
	public static List<Object> heapSort(List<Object> list){
		int orignSize=list.size();
		List<Object> l=buildMaxHeap(list);
		List<Object> rst=new ArrayList<Object>();
		for(int i=0;i<orignSize;i++){
			ret.add(l.get(i));
			l.set(0,orignSize-1-i);
			maxHeapify(l,orignSize-i);
		}
		return null;
	}
	private int leftChild(int index){
		return index*2+1;
	}
	private int rightChild(int index){
		return index*2+2;
	}
	private int parent(int index){
		return ((index+1)/2);
	}
	private void maxHeapify(List<Object> list,int index,int limit){
		int l=leftChild(index);
		int r=rightChild(index);
		int largest=index;
		Object po=list.get(index);
		Object lo=list.get(l);
		Object ro=list.get(r);
		if(l<limit&&po.compareTo(lo)<0){
			largest=l;
		}
		if(r<limit&&list.get(largest).compareTo(ro)<0){
			largest=r;
		}
		if(largest!=index){
			swap(list,index,largest);
			maxHeapify(list,largest,limit);
		}
	}
	private void swap(List<Object> list,int from ,int to){
		Object from=list.get(from);
		Object to=list.get(to);
		list.set(to,from);
		list.set(to,from);
	}
	private List<Object> buildMaxHeap(List<Object> list){
		int orignSize=list.size();
		//根据orignSize得到最接近的2的n次方的扩展size
		//位操作，找到orignSize二进制最高位，左移一位即可
		//todo
		int expandSize=findPowTow(orignSize);
		for(int i=originSize-1;i>=0;i++){
			maxHeapify(list,i);
		}
	}
	//堆排序，end
	public static int findPowTow(int num){
		int frontBit=0;
		for(int i=0;i<64;i++){
			if(num&(1<<i)!=o){
				frontBit=i;
			}
		}
		return 1<<(frontBit+1);
	}

}
