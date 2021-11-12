<template>
  <div>
    <el-select
      v-model="selectVal"
      @visible-change='visibleChange'
      @change="selectChange"
      @clear='clear'
      v-loadMore='loadMore()'
      :loading='loading'
      :filter-method="filterMethod"
      clearable
      filterable>
      <el-option
        key=""
        label=""
        value="">
      </el-option>
      <el-option
        v-for="(item, index) in opt"
        :key="index"
        :label="item.name"
        :value="item.id">
      </el-option>
    </el-select>
  </div>
</template>

<script>
export default {
  components : {},
  props : {
    arr : {
      type : Array,
      default : function () {
        return []
      },
      require : false
    },
    number : {
      type : Number,
      default : 20,
      require : false,
      validator : function (val) {
        return Math.round(val) === val
      }
    }
  },
  data () {
    return {
      selectNumber : 20,
      filterKey : '',
      loading : true,
      select : false,
      oldSelect : '',
      selectVal : '',
      allOpt : [],
    }
  },
  computed : {
    opt () {
      if(!this.filterKey){
        return this.allOpt.slice(0, this.selectNumber)
      }
      return this.allOpt.filter(item => item.name.indexOf(this.filterKey) > -1).slice(0, this.selectNumber)
    },
  },
  created () {
    //可从后台获取数据，比如select的下拉框数据
  },
  methods : {
    loadMore () {
      return () => (this.selectNumber += 5)
    },
    visibleChange (flag) {
      //下拉框打开或关闭，关闭时判断是否选择，需要用到oldSelect
      if(flag){
        this.select = false//选择标识置为false
        this.oldSelect = this.selectVal
      }else{
        if(!this.select){
          let obj = this.allOpt.filter(item => item.id == this.oldSelect)[0] ? this.allOpt.filter(item => item.id == this.oldSelect)[0] : {}
          this.id = obj.id ? obj.id : ''
          this.filterKey = ''
        }
      }
    },
    clear () {
      this.filterKey = ''
    },
    selectChange (val) {
      this.select = true
      if(!val){
        this.filterKey = ''
        this.id = ''
      }
    },
    filterMethod (val) {
      this.id = val
      this.filterKey = val
      this.selectNumber = 20
      this.oldSelect = ''
    }
  }
}
</script>