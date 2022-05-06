package chap19;

import java.io.IOException;

public class Interface {
	public static void main(String[] args) throws IOException{
		System.out.println("��ȭ ���� �Ҵ� ����� �����ϼ���.");
        System.out.println("R : �Ѹ� ���ʴ��");
        System.out.println("L : ��Ⱑ ���� ���� �켱");
        System.out.println("P : �켱������ ���� ���켱 ���õ� ���� ����");

        int ch=System.in.read();
        Scheduler scheduler=null;

        if(ch == 'R' || ch=='r') {
            scheduler=new RoundRobin();
        }
        else if(ch == 'L' || ch=='l') {
            scheduler=new LeastJob();
        }else if(ch == 'P' || ch=='p') {
            scheduler=new PriorityAllocation();
        }else {
         System.out.println("�������� �ʴ� ����Դϴ�");
         return;
        }
        scheduler.getNextCall();
        scheduler.sendCallToAgent();
	}
}

interface Scheduler{
	public void getNextCall();
	public void sendCallToAgent();
}

class RoundRobin implements Scheduler{
	public void getNextCall() {
		System.out.println("��� ��ȭ�� ������� ��⿭���� �����ɴϴ�.");
	}
	
	public void sendCallToAgent() {
		System.out.println("���� ������ �������� ����մϴ�.");
	}
}

class LeastJob implements Scheduler{
	public void getNextCall() {
		System.out.println("��� ��ȭ�� ������� ��⿭���� �����ɴϴ�.");
	}

	public void sendCallToAgent() {
		System.out.println("���� �������� ���ų� ����Ⱑ ���� ���� �������� �Ҵ��մϴ�.");
	}
	
}

class PriorityAllocation implements Scheduler{
    public void getNextCall() {
        System.out.println("�� ����� ���� ���� call�� ���� �����ɴϴ�.");

    }

    public void sendCallToAgent() {
        System.out.println("���� ���õ��� ���� �������� ���� ����մϴ�.");

    }
}