function [e] = qiege(d)%  �и����С��Χ
[m,n]=size(d);
top=1;bottom=m;left=1;right=n;
while sum(d(top,:))==0&&top<=m
    top=top+1;
end
while sum(d(bottom,:))==0&&bottom>=1
    bottom=bottom-1;
end
while sum(d(:,left))==0&&left<=n
    left=left+1;
end
while sum(d(:,right))==0&&right>=1
    right=right-1;
end
dd=right-left;
hh=bottom-top;
e=imcrop(d,[left top dd hh]);
% I2=imcrop(I,[a b c d]);
%���òü������ü�ͼ�����У���a,b����ʾ�ü������Ͻ�������ԭͼ���е�λ�ã�
%c��ʾ�ü���ͼ��Ŀ�d��ʾ�ü���ͼ��ĸ�