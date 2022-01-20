<template>
  <div id="app">
    <router-view v-if="isRouterAlive" />
  </div>
</template>

<script>
export default {
  name : 'App',
  provide () {
    return {
      reload : this.reload
    }
  },
  data () {
    return {
      isRouterAlive : true
    }
  },
  created () {
    window.$app = this
    /* particlesJS.load(@dom-id, @path-json, @callback (optional)); */
    window.particlesJS.load('app', '../src/components/bgc-animate/particles.json', function() {
  console.log('callback - particles.js config loaded');
});
  },
  methods : {
    reload () {
      this.isRouterAlive = false
      this.$nextTick(() => {
        this.isRouterAlive = true
      })
    }
  }
}
</script>