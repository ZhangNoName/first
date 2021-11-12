<template>
  <div
    style="hieght:100%;width:100%;overflow:auto">
    <el-table
      id="table"
      ref="table"
      :data="visualTable"
      v-loading='loading'
      highlight-current-row
      empty-text=""
      height="100%"
      row-key="id"
      style="width:100%">
      <el-table-column
        type="selection"
        width="30px"
        reserve-selection>
      </el-table-column>
      <el-table-column
        label="名称"
        prop="name"
        min-width="100px">
      </el-table-column>
    </el-table>
  </div>
</template>

<script>
import {_debounce} from '@/selfFunction/_debounce.js'
export default {
  data () {
    return {
      scrollTop : 0,
      startIndex : 0,
      num : 20,
      loading : false,
      tableAllData : [],
    }
  },
  computed : {
    tableData () {
      //可以在这里对所有数据进行筛选，并且通过computed属性实现对数组的监听，
      //但computed不可改变，无setter，可自定义setter
      let arr = this.tableAllData
      // eslint-disable-next-line vue/no-side-effects-in-computed-properties
      this.startIndex = 0
      if(this.$refs.table){
        // eslint-disable-next-line vue/no-side-effects-in-computed-properties
        this.$refs.table.bodyWrapper.scrollTop = 0
      }
      if(arr.length < 20 && this.$refs.table){
        this.$refs.table.clearSelection()
        let obj = this.$refs.table
        obj.bodyWrapper.removeEventListener('scroll', this.debounceFn)
        this.$nextTick(() => {
          this.scrollTop = 0
          this.calcList(this.scrollTop)
        })
      }
      if(arr.length > 20 && this.$refs.table){
        this.$refs.table.clearSelection()
        this.$nextTick(() => {
          this.debounceFn = _debounce(() => {
            this.scrollTop = this.$refs.table.bodyWrapper.scrollTop
          }, 100)
          this.$refs.table.bodyWrapper.addEventListener('scroll', this.debounceFn)
          this.calcList(this.scrollTop)
        })
      }
      return arr
    },
    visualTable () {//显示数据
      return this.tableData.slice(this.startIndex, this.startIndex + this.num)
    }
  },
  watch : {
    scrollTop (top) {
      this.calcList(top)
    },

  },
  created () {
    for(let i=0;i<1000;i++){
      this.tableAllData.push({
        name : '第' + i + '个',
        id : i,
      })
    }

  },
  methods : {
    calcList (top = this.scrollTop) {
      let height = this.tableData.length * 22
      this.startIndex = Math.floor(top/22)
      let table = this.$refs.table.$el.getELementsByClassName('el-table__body')
      Array.from(table).forEach(v => {
        v.style.height = height + 'px'
        if(this.startIndex + this.num >= this.tableData.length){
          v.style.scrollTop = top > 22 ? (this.scrollTop - 22 + 'px') : 0
          v.style.paddingBottom = 0
        }else{
          v.style.scrollTop = top + 'px'
          v.style.paddingBottom = height - this.num * 22 - top + 'px'
        }
      })
    }
  }
}
</script>