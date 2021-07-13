<template>
    <div class="flex flex-col h-63 w-49 absolute top-1/4 left-1/4">
        <div class="h-14">
            <div class="float-left h-1/2"> {{time}}</div>
            <div class="float-right grid grid-cols-3 gap-4">
                <button 
                    @click="changeMonth(-1)" 
                    class="rounded hover:bg-gray-200"
                >上月</button>
                <button 
                    class="rounded hover:bg-gray-200"
                    @click="getTime()" 
                >本月</button>
                <button 
                    class="rounded hover:bg-gray-200"
                    @click="changeMonth(1)" 
                >下月</button>
            </div>
            <div class="grid grid-cols-7 h-1/2 w-full">
                <div 
                    v-for="(item,index) in WEEK" 
                    :key="index" 
                >{{item}}</div>
            </div>
        </div>
        <div class="grid grid-cols-7 grid-rows-6 h-42 w-full">
            <div 
                v-for="(item,index) in clendarData" 
                :key="index" 
                tabindex = "0" 
                :class="setCss(item.status)"
                @click="chooseDay(item.day,item.status)"  
            >{{item.day}}</div>
        </div>
    </div>
</template>
<script>
export default {
    model:{
        prop:'setTime',//定义接收父组件v-model绑定的值，名称须和props中定义相同
        event:'test',//自定义事件名称，v-model本质为单向数据流，双向传参由v-on和v-bind组成，定义的v-on事件名称为test（可以任意定义）                    //子组件像父组件传值可以通过$emit('test',值)的形式完成传递，
    },
    props:{
        // setTime:{
        //     type:Array,
        //     default:()=>{
        //         this.getTime();
        //         return [this.thisYear,this.thisMonth,this.today]
        //     }
        // },
        setTime:Array,//必须定义一个接收父组件进行传参的变量，函数参考下面model的prop
        
    },
    data(){
        return {
            //衍生状态-核心状态
            //衍生状态是基于其他变量进行改变而改变的，比如time是由thisMonth和thisYear进行拼接形成的
            //在thisMonth和thisYear没有改变的情况下，time不会改变，所以可以通过写到computed减少计算量
            //相似的还有monthStartWeek和monthDays，两者都是在thisMonth和thisYear确定的情况下确定的
            //也就是两者的值是被thisMonth和thisYear决定的，属于衍生状态
            //本组件核心状态就只有thisMonth和thisYear，两者决定了展示的数据，所以展示的数据calendarData也
            //属于衍生状态，可以设为computed，
            //除核心状态之外的都是衍生状态，设计时应尽可能的考虑节省性能
            //
            //常量：定义之后不会进行改变的量，比如本次的week，命名要大写，多个单词之间下划线链接
            //
            //考虑v-model，看源码，单项数据流，不要怕麻烦

            //编码风格，根据vue官方建议来改，在vue官网风格指南
            //检查格式设置，尽可能简化
            //watch的三种写法，根据合适的进行，完整的immediately可设置初始化的时候是否执行
            //带有数字的写清楚数字的名称
            //尽可能去除不必要变量，如selectTime
            //熟练使用各种布局，宽度确定，宽度不定。
            //规范每个模块的书写顺序，比如computed，methods，watch等排序

            //clendarData:[],
            thisMonth:null,//当前月
            thisYear:null,//当前年
            thisDay:null,//当前日
            thisDate:null,//当前星期 星期常用weekday
            today:null,//今天
            // lastMonth:null,//下一个月
            // nextMonth:null,//上一个月
            //time:"",//显示时间
            WEEK:["日","一","二","三","四","五","六"],//常量名称大写加下划线
            //monthStartWeek:null,
            //monthDays:null,//月天数
            selectTime:null,

        }
    },
    computed:{
        clendarData(){
            let data=[];
            for(let i=0;i<this.monthStartWeek;i++){
                data.push({day:this.lastMonthDays-this.monthStartWeek+1+i,status:-1});
            }
            for(let i=1;i<=this.monthDays;i++){
                data.push({day:i,status:0});
            }
            for(let i=1;data.length<42;i++){
                data.push({day:i,status:1});
            }   
            if(this.thisDay){
                //this.lastChooseDay=this.monthStartWeek+this.thisDay-1;
                data[this.monthStartWeek+this.thisDay-1].status=2;           
            }      
             let date = new Date();
             let thisYear = date.getFullYear();
             let thisMonth= date.getMonth() + 1;
             let thisDate=date.getDate();
            if(this.thisYear==thisYear&&this.thisMonth==thisMonth){
                data[this.monthStartWeek+thisDate-1].status=3;
            }
            return data;
        },
        monthStartWeek(){
            let date=new Date(this.thisYear,this.thisMonth-1,1);
            let week=date.getDay();
            return week;
        },
        monthDays(){
            let date=new Date(this.thisYear,this.thisMonth,0);
            let days=date.getDate();
            return days;
        },
        lastMonthDays(){
            let date=new Date(this.thisYear,this.thisMonth-1,0);
            let days=date.getDate();
            return days;
        },
        time(){
            let s="";
            s=this.thisYear+"年"+this.thisMonth+"月";
            return s;
        }
    },
    watch:{
        setTime:'resolveSetTime',
    }, 
    created(){
        this.resolveSetTime();
    },
    methods:{
        getTime(){
            var date = new Date();
            this.thisYear = date.getFullYear();
            this.thisMonth= date.getMonth() + 1;//monthIndex+1
            this.today=date.getDate();
            //var day = date.getDate();
            //this.time=this.thisYear+"年"+this.thisMonth+"月";
        },
        setCss(status){
            let s="rounded hover:bg-gray-200 ";
            if(status==-1||status==1){
                s+="text-gray-400";
            }else if(status==2){
                s+="bg-blue-300 text-white";
            }else if(status==3){
                s+="text-red-500";
            }
            return s;
        },
        changeMonth(num){
            this.thisMonth+=num;
            if(this.thisMonth==0){
                this.thisMonth=12;
                this.thisYear--;
            }else if(this.thisMonth>12){
                this.thisMonth=1;
                this.thisYear++;
            }    
        },
        chooseDay(day,status){
            if(this.thisDay){
                this.clendarData[this.monthStartWeek+this.thisDay-1].status=0;
            }
            this.thisDay=day;
            this.clendarData[this.monthStartWeek+this.thisDay-1].status=2;
            if(status==-1 || status==1){
                this.changeMonth(status);
            }
            this.$nextTick(() => {
                this.selectTime=[this.thisYear,this.thisMonth,this.thisDay];
                //this.$emit('changeTime',this.selectTime);
                this.$emit('test',this.selectTime);
                console.log(this.setTime);
            });
        },
        resolveSetTime(){
            this.thisYear=this.setTime[0];//解构赋值，若直接序号访问，则对序号做出说明
            this.thisMonth=this.setTime[1];
            this.thisDay=this.setTime[2];
        }
    },
    
}

</script>

<style>

</style>