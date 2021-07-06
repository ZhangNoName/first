<template>
    <div  class="flex flex-col h-56 w-49 absolute top-1/4 left-1/4">
        <div class="h-14">
            <div class="float-left h-1/2"> {{time}}</div>
            <div class="float-right grid grid-cols-3 gap-4h-1/2">
                <button @click="changeMonth(-1)" class="rounded hover:bg-gray-200">上月</button>
                <button @click="reSet()" class="rounded hover:bg-gray-200">本月</button>
                <button @click="changeMonth(1)" class="rounded hover:bg-gray-200">下月</button>
            </div>
            <div class="grid grid-cols-7 h-1/2 w-full">
                 <div v-for="(item,index) in week" :key="index" class="active:bg-red-300">{{item}}</div>
            </div>
        </div>
        <div class="grid grid-cols-7 grid-rows-6 h-42 w-full">
            <div tabindex = "0" v-for="(item,index) in clendarData" :key="index" @click="chooseDay(item.day)"  :class="setCss(item.status)">{{item.day}}</div>
        </div>
    </div>
</template>
<script>
export default {
    data(){
        return {
            clendarData:[],
            thisMonth:null,//当前月
            thisYear:null,//当前年
            thisDay:null,//当前日
            thisDate:null,//当前星期
            today:null,//今天
            lastMonth:null,//下一个月
            nextMonth:null,//上一个月
            time:"",//显示时间
            week:["日","一","二","三","四","五","六"],
            monthStartWeek:null,
            monthDays:null,//月天数
            lastChooseDay:null,
        }
    },
    created(){
        this.getTime();
        this.setCalendarData(this.thisYear,this.thisMonth);

    },
    computed:{

    },
    methods:{
        getTime(){
            var date = new Date();
            this.thisYear = date.getFullYear();
            this.thisMonth= date.getMonth() + 1;//monthIndex+1
            //var day = date.getDate();
            this.time=this.thisYear+"年"+this.thisMonth+"月";
        },
        getMonthDays(year,month){//获取month月天数
            var date=new Date(year,month,0);
            var days=date.getDate();
            return days;
        },
        getMonthStartWeek(year,monthIndex){
            var date=new Date(year,monthIndex,1);
            var week=date.getDay();
            return week;
        },
        setCalendarData(year,month){
            this.monthStartWeek=this.getMonthStartWeek(year,month-1);
            //console.log(this.monthStartWeek);
            this.monthDays=this.getMonthDays(year,month);
            var lastMonthDays=this.getMonthDays(year,month-1);
            this.clendarData=[];
            for(let i=0;i<this.monthStartWeek;i++){
                this.clendarData.push({day:lastMonthDays-this.monthStartWeek+1+i,status:0});
            }
            for(let i=1;i<=this.monthDays;i++){
                this.clendarData.push({day:i,status:1});
            }
            for(let i=1;this.clendarData.length<42;i++){
                this.clendarData.push({day:i,status:0});
            }
            this.time=this.thisYear+"年"+this.thisMonth+"月";
            if(this.thisDay){
                this.lastChooseDay=this.monthStartWeek+this.thisDay-1;
                this.clendarData[this.monthStartWeek+this.thisDay-1].status=2;           
                //console.log(this.thisDay+"已标为2");
            }      
            
             let date = new Date();
             let thisYear = date.getFullYear();
             let thisMonth= date.getMonth() + 1;
             let thisDate=date.getDate();
            if(this.thisYear==thisYear&&this.thisMonth==thisMonth){
                this.clendarData[this.monthStartWeek+thisDate-1].status=3;
                //console.log(thisDate+"已标为3");
            }     
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
            this.setCalendarData(this.thisYear,this.thisMonth);    
        },
        reSet(){
            this.getTime();
            this.setCalendarData(this.thisYear,this.thisMonth);
        },
        chooseDay(day){
            this.thisDay=day;
            if(this.lastChooseDay){
                this.clendarData[this.lastChooseDay].status=1;
            }
            console.log(this.thisDay);
        },
        setCss(status){
            var s="rounded hover:bg-gray-200 focus:bg-blue-300 focus:text-white ";
            if(status==0){
                s+="text-gray-400";
                //console.log(status,s);
            }else if(status==2){
                s+="bg-blue-300 text-white";
                //console.log(status,s);
            }else if(status==3){
                s+="text-red-500";
                //console.log(status,s);
            }
            return s;
        }
    },
    watch:{
    }   
}

</script>

<style>
.test{
    @apply rounded hover:bg-gray-200 focus:bg-blue-300 focus:text-white ;
}
</style>