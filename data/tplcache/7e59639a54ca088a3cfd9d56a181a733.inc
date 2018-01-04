<li class="menu-item mega-menu menu-item-type-taxonomy mega-menu menu-item-object-category mega-menu menu-item-has-children parent-list"> <a href="{dede:field name='typeurl'/}">{dede:field name='typename'/}<span class="sub-indicator"></span></a><!-- 顶级栏目 -->
<div class="mega-menu-block">
<div class="mega-menu-content"> 
<!-- 当前栏目带图头条 --> 
{dede:arclist orderby='rand' row='3' titlelen='60' type='image'}
<div class="mega-menu-item "> <a href="[field:arcurl/]" title="[field:title/]"> <img src="[field:litpic/]" width="235" height="117"></a>
<h3 class="post-box-title"> <a class="mega-menu-link" href="[field:arcurl/]" title="[field:title/]">[field:title/]</a> </h3>
</div>
{/dede:arclist} 
<!-- 当前栏目带图头条结束 --> 
</div>
<!--当前子栏目-->
<ul class="sub-menu">
{dede:channel type='son' noself='yes'}
<li class="menu-item  menu-item-type-taxonomy  menu-item-object-category"> <a href="[field:typelink/]">[field:typename/]</a></li>
{/dede:channel}
</ul>
<!--当前子栏目end--> 
</div>
</li>