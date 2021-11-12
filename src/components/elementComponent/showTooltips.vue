<template>
  <el-popover
    :placement="location"
    :disabled='isDisabled'
    trigger="hover"
    :close-delay='100'>
    <span style="font-size:12px">{{info}}</span>
    <div
      slot="reference"
      class="wordnowarp"
      @mouseenter="isShowPopover"
      @click="linkTo">
      {{info}}
    </div>
  </el-popover>
</template>

<script>
export default {
  name : 'showTooltips',
  props : {
    info : {
      type : String,
      default : '',
      require : false
    },
    location : {
      type : String,
      default : 'right',
      require : false
    },
    isLink : {
      type : Boolean,
      default : false,
      require : false
    }
  },
  data () {
    return {
      isDisabled : false,
    }
  },
  methods : {
    isShowPopover (e) {
      let clientWidth = e.target.clientWidth
      let scrollWidth = e.target.scrollWidth
      let arrList = Array.from(e.target.classList)
      if(scrollWidth > clientWidth){
        this.isDisabled = false
        if(!arrList.includes('hover-blue')){
          e.target.classList.add('hover-blue')
        }
      }else{
        this.isDisabled = true
        e.target.classList.remove('hover-blue')
      }
    },
    linkTo () {
      if(this.isLink){
        this.$emit('linkTo')
      }
    }
  }
}
</script>

<style scoped>
  .wordnowrap {
    overflow: hidden;
    text-overflow: ellipsis;
    white-space: nowrap;
  }
  .hover-blue {
    color: rgb(59, 128, 198);
  }
  .link-text{
    color: rgb(59, 128, 198);
    cursor: pointer;
  }
  .el-popover {
    font-size: 12px;
  }
</style>