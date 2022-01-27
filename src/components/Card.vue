<template>
  <div class="container">
    <a 
      class="card-title" 
      :title="name" 
      :href="path">
      {{name}}
      </a>
    <div class="card-meta">
      <span >
        <i></i>
        <span>created</span>
        <time 
          :datetime="time"
          :title="time"
          >
          {{time}}
          </time>
      </span>
      <span>
        <span></span>
        <i></i>
        <a 
          class=""
          href="#">
        </a>
      </span>
      <span>
        <span></span>
        <i></i>
        <a 
          class=""
          href="#">
        </a>
      </span>
    </div>
    <div class="card-describe"> 
      {{describe}}
    </div>
  </div>
</template>

<script>
export default {
  props: {
    name : {
      type : String,
      required : true,
    },
    classify : {
      type : String,
      required : true,
    },
    label : {
      type : [String, Array],
      required : true,
    },
    createTime : {
      type : String,
      required : true,
    },
    describe : {
      type : String,
      required : true,
    },
    path : {
      type : String,
      required : true,
    }
  },
  data () {
    return {

    }
  },
  methods: {

  }
}
</script>

<style scoped>
.container{

}
</style>